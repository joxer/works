(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(inhibit-startup-screen t)
 '(kill-ring-max 100))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )



(defun kill-here (arg word) ; CREATED BY ME D: D: D:
  (interactive "*nInsert number: \nMInsert text: \n")
  (setq here (point))
  (setq found (search-forward word nil t  arg))
  (kill-region here found)
)

(load-file "~/.emacs.d/auto-complete.el" )
(load-file "~/.emacs.d/artist.el" )
(require 'artist)
(require 'auto-complete)
(global-auto-complete-mode t)
