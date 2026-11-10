function Process(Type)
    global Stop;
    Stop = 0;
    vid = imaqfind;
    handles = guihandles(GUI);

    for Ind = 1:Inf
        if (Stop)
            break;
        else
            try
                if (~Stop)
                    drawnow;
                    img = getsnapshot(vid);
                    if ~get(handles.Flip_Image, 'Value')
                        img = cat(3, flipud(img(:,:,1)), flipud(img(:,:,2)), flipud(img(:,:,3)));
                    end
                    
                    if(strcmp(Type, 'Cal'))
                        Path = get(handles.Location, 'UserData');
                        Path = strcat(Path, '\Cal_');
                        Path = sprintf('%s%d.png', Path, Ind);
                        imwrite(img, Path, 'png');
                        text('units', 'pixels', 'position', [100 100], 'fontsize', 11, ...
                             'string', 'Acquiring Calibration Data', 'Color', [.5 .6 .4]);
                    elseif(strcmp(Type, 'Acq'))
                        Cmd = Gaze_Direction(img);
                        Iris2Mouse(Cmd);
                        text('units', 'pixels', 'position', [100 100], 'fontsize', 18, ...
                             'string', Cmd, 'Color', [.5 .6 .4]);
                    end
                end
            catch
            end
        end
    end
end
